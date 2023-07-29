if(isArithmetic(node->type))
    {
        //fprintf(stderr, "NODE AND TYPE: %d\n", node->type);
        if (!(isArithmetic(node->children[0]->type)))
        {
            if(node->children[0]->symbol->type) 
                if(isBool(node->children[0]->symbol->type) || isLogic(node->type || isRelational(node->type)))
                    {
                        fprintf(stderr, "Arithmetic operation incompatible types.\n");
                        SemanticErrors++;
                    }
        }
        if (!(isArithmetic(node->children[1]->type)))
        {
            if(node->children[1]->symbol->type) 
                if(!(isChar(node->children[1]->symbol->type) || isInt(node->children[1]->symbol->type)))
                    {
                        fprintf(stderr, "Arithmetic operation incompatible types.\n");
                        SemanticErrors++;
                    }
        }
        if(!(isArithmetic(node->children[0]->type) && isArithmetic(node->children[1]->type)))
        {
            if(node->children[0] != NULL && node->children[1] != NULL)
            {
                if(!IsCompatibleForOperation(node->children[0]->symbol->dataType, node->children[1]->symbol->dataType))
                {
                    fprintf(stderr, "Arithmetic operation incompatible types 2.\n");
                    SemanticErrors++;
                }
            }
        }
    }